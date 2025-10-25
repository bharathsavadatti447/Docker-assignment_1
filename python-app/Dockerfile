FROM python:3.12-slim

WORKDIR /python-app

COPY word_count.py sample.txt requirements.txt ./

RUN pip install -r requirements.txt

EXPOSE 8000

CMD ["python", "word_count.py"]
