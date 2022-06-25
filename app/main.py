
#from flask import Flask
#
#app = Flask(__name__)
#
#@app.route("/")
#def home_view():
#    return "<h1>Finalmente heroku funcionou!!!</h1>"

from ast import And
from distutils.log import debug
import sqlite3
import os
#from tkinter import INSERT
from flask import Flask, request, render_template, redirect

#debug = true

app = Flask(__name__)
#app.config['SECRET_KEY'] = os.urandom(24).hex

connection = sqlite3.connect('app.db', check_same_thread=False)
cur = connection.cursor()

name_user = 'E_agricultor_admin'
password = 2005294
email = 'undefined@Eagri.com.br'
cep = 99999999

@app.route('/')
def index():
    app = Flask(__name__)
    return render_template("app/templates/index.html")

@app.route('/login', methods =["GET", "POST"])
def login():
    if request.method == "POST":
        user = request.form.get("nuser")
        keyword = request.form.get("key")
        if (user == name_user) and (int(keyword) == password):
            return redirect('/dashboard')
        else:
            return "<h1>Login Error Value</h1>"
    return render_template("login.html")

@app.route('/dashboard')
def dashboard():
    return render_template("dashboard.html", name_user_html=name_user)


'''
CREATE TABLE "peaples" (
	"name"	text NOT NULL,
	"password"	integer NOT NULL,
	"email"	text NOT NULL,
	"cep"	NUMERIC NOT NULL,
	"Id"	INTEGER NOT NULL,
	PRIMARY KEY("Id" AUTOINCREMENT)
);
'''
            
    #cur.execute("INSERT INTO peaples(name,password,email,cep) VALUES(?,?,?,?)", (name_user, password, email, cep))
    #connection.commit()
    #connection.close()