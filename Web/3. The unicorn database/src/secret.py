from flask import Flask, render_template, redirect, url_for, request, g, session, abort, send_file
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
import base64
import os
import sqlite3
app = Flask(__name__)
app.config.update(dict(SECRET_KEY=os.urandom(16)))

def connect_db():
    db = sqlite3.connect("file:./secret_database.sqlite3?mode=ro", uri=True)
    db.row_factory = sqlite3.Row
    return db

def get_db():
    if not hasattr(g, 'db'):
        g.db = connect_db()
    return g.db

def hash_bytes(b):
    digest = hashes.Hash(hashes.SHA384(), backend=default_backend())
    digest.update(b.encode())
    return digest.finalize()

@app.route("/", methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        pass_digest = hash_bytes(request.form['password'])
        pass_b64 = base64.b64encode(pass_digest).decode()
        db = get_db()
        cur = db.execute(f"SELECT * FROM Users WHERE username = '{request.form['username']}' AND password = '{pass_b64}'")
        entries = cur.fetchall()
        if len(entries) > 0:
            session['logged_in'] = True
            return redirect(url_for('flag'))
        else:
            return redirect(url_for('login'))
    return render_template('index.html')

@app.route("/flag")
def flag():
    if not session.get('logged_in'):
        abort(401)
    return "Well done my friend, your flag is: UiTHack19{and_remember_kids_we_are_all_unicorns}"