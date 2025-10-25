# word_count.py
from flask import Flask

app = Flask(__name__)

@app.route("/")
def count_words():
    with open('sample.txt', 'r') as f:
        text = f.read()
    word_count = len(text.split())
    return f"Word Count: {word_count}"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
