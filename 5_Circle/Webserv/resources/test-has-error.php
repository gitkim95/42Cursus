<!DOCTYPE html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="data:,">
    <title>Welcome to PHP</title>
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
    <h1>Welcome to PHP</h1>
</header>

<main>
    <div class="content">
        <h2>Your Request Information</h2>
        <p><strong>Request Method:</strong> 
            <?php
				function_not_exist();
                echo $_SERVER['REQUEST_METHOD'];
            ?>
        </p>
        <br />
        <?php
            if (isset($_REQUEST['name']) && !empty($_REQUEST['name'])) {
                $name = htmlspecialchars($_REQUEST['name']);
                echo "<p><strong>Hello, " . $name . "!</strong></p>";
            } else {
                echo "<p><strong>Hello, World from PHP!</strong></p>";
            }
        ?>
    </div>
</main>

</body>
</html>