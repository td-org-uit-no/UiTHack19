from flask import Flask, render_template, redirect, url_for, request, g, session, abort, send_file, make_response
import os
import sqlite3
app = Flask(__name__)
app.config.update(dict(SECRET_KEY=os.urandom(16)))

# admin_cookie = "access_token=access:true"
# users_cookie = "access_token=access:false"

@app.route("/", methods=['GET', 'POST'])
def index():
    print("the request = ", request.method)
    if request.method == 'GET':
        if not request.cookies.get('access_token'):
            access_token = make_response(render_template('index.html'))
            access_token.set_cookie('access_token', 'false')
        else:
            access_token = request.cookies.get('access_token')
            print("access_token GET :  ", access_token)

    if request.method == 'POST':
        
        access_token = request.cookies.get('access_token')
        print("access_token POST :  ", access_token)

        try:
            if 'true' in access_token:
                session['logged_in'] = True
                return redirect(url_for('flag'))
        except:
            return render_template('index.html')

    return render_template('index.html')



@app.route("/flag")
def flag():
    if not session.get('logged_in'):
        abort(401)
    return "Well done my friend, your flag is: UiTHack19{testing}"