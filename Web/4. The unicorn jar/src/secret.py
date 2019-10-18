from flask import Flask, render_template, redirect, url_for, request, g, session, abort, send_file, make_response
import os
app = Flask(__name__)
app.config.update(dict(SECRET_KEY=os.urandom(16)))

@app.route("/", methods=['GET', 'POST'])
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
    if user_id == 'true':
        return redirect(url_for('flag'))
    else:
        return redirect(url_for('login'))

@app.route("/flag")
def flag():
    if not request.cookies.get('access_token') == 'true':
        abort(401)
    return "You got my cookie! UiTHack19{cant_keep_my_hands_out_the_cookie_jar}"