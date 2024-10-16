from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return "Welcome to CU Smart Course Portal!"

if __name__ == '__main__':
    app.run(debug=True)
