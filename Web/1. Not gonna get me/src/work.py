from flask import Flask, render_template, redirect, url_for, request, g, session, abort, send_file
import os
import sqlite3
app = Flask(__name__)
app.config.update(dict(SECRET_KEY=os.urandom(16)))

@app.route("/")
def index():
    return render_template('index.html')

@app.route("/flag")
def flag():
    return "You didn't work that hard for it: UiTHack19{oooh_you_got_me}"