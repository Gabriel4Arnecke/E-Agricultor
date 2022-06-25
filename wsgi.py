from distutils.debug import DEBUG
from app.main import app

DEBUG = True
ALLOWED_HOST = []

if __name__ == "__main__":
    app.run()