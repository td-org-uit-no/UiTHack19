from flask import Flask, render_template, redirect, url_for, request, g, session, abort, send_file
import os

app = Flask(__name__)
app.config.update(dict(SECRET_KEY=os.urandom(16)))

@app.route('/', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        if request.form['username'] == 'admin' and request.form['password'] == 'gunther milo birk':
            session['logged_in'] = True
            return redirect(url_for('secret_page'))
        else:
            return redirect(url_for('index.html'))
    return render_template('index.html')

@app.route('/secret_page', methods=['POST'])
def secret_page():
    login()
    if not session.get('logged_in'):
        abort(401)
    return "UiTHack2019{comment_your_code_they_say_it_is_important_they_say}"