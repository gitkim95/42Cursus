#!/usr/bin/python3
import cgi
import cgitb
import os

print('''<!DOCTYPE html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="data:,">
    <title>Welcome to Python CGI</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f0f8ff;
            margin: 0;
            padding: 0;
        }

        header {
            background-color: #4CAF50;
            color: white;
            padding: 20px;
            text-align: center;
        }

        main {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 80vh;
            text-align: center;
        }

        .content {
            background-color: #fff;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            max-width: 500px;
            width: 100%;
        }
    </style>
</head>
<body>

<header>
    <h1>Welcome to Python CGI</h1>
</header>

<main>
    <div class="content">
        <h2>Your Request Information</h2>
        <p><strong>Request Method:</strong> ''')

print(os.environ.get('REQUEST_METHOD', 'N/A'))

print('''</p>
        <br />''')

form = cgi.FieldStorage()
name = form.getvalue('name')

if name and name.strip():
    from html import escape
    print(f"<p><strong>Hello, {escape(name)}!</strong></p>")
else:
    print("<p><strong>Hello, World from Python CGI!</strong></p>")

print('''    </div>
</main>

</body>
</html>''')