from flask import Flask, render_template, redirect, url_for, request, g, session, abort, send_file, make_response
import os
import sqlite3
app = Flask(__name__)
app.config.update(dict(SECRET_KEY=os.urandom(16)))

# admin_cookie = "access_token=access:true"
# users_cookie = "access_token=access:false"
@app.route("/")
def cookie():
    cookie_id = request.cookies.get('access_cookie')
    print("cookie id : ", cookie_id)
    if cookie_id:
        print("In cookie first")
        if cookie_id == 'true':
            print("In cookie")
            # Success!
            session['logged_in'] = True
            return redirect(url_for('flag'))
        else:
            return redirect(url_for('login'))
    else:
        return redirect(url_for('login'))

@app.route("/login", methods=['GET', 'POST'])
def login():
    print("the request = ", request.method)
    if request.method == 'POST':
        res = redirect(url_for('check_cookie'))
        res.set_cookie('access_token', 'false')
        return res
    return render_template('index.html')

@app.route("/check_cookie")
def check_cookie():
    user_id = request.cookies.get('access_token')
    if user_id:
        if user_id == 'true':
            # Success!
            print("KOMMER HIT")
            session['logged_in'] = True
            return redirect(url_for('flag'))
        else:
            return redirect(url_for('login'))
    else:
        return redirect(url_for('login'))

@app.route("/flag")
def flag():
    if not request.cookies.get('access_token') == 'true' or not session['logged_in']:
        abort(401)
    return "Well done my friend, your flag is: UiTHack19{testing}"