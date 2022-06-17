from flask import Flask, render_template
app = Flask(__name__)

name_user = 'Gabriel Arnecke'

@app.route('/')
def index():
    return render_template("index.html")

@app.route('/login')
def login():
    return render_template("login.html")

@app.route('/dashboard')
def dashboard():
    return render_template("dashboard.html", name_user_html=name_user)
    