from flask import Flask, render_template, g

import sqlite3

app = Flask(__name__)

DB_URL = "app.db"

@app.route('/dashboard')
def dashboard():
    return x

@app.route('/')
def index():
    return
    

@app.before_request
def before_request():
    conn = sqlite3.connect(DB_URL)
    cursor = conn.cursor()

@app.teardown_request
def after_request():
    if g.conn is not None:
        g.conn.close()

@auth.route('/signup')
def signup():
    return render_template('login.html')

#cursor.execute("CREATE TABLE peaples (name text, password integer, email text)")