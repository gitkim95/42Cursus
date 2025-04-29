<!-- test.php -->
<head>
	<link rel='icon' href='data:,'>
	<title>Welcome to PHP</title>
</head>
<body>
	<?php
		echo "REQUEST_METHOD: " . $_SERVER['REQUEST_METHOD'];
	?>
		<br />
		<br />
	<?php
	    if (isset($_REQUEST['name'])) {
	        $name = htmlspecialchars($_REQUEST['name']);
	        echo "Hello, " . $name . "!";
	    } 
	    else {
	        echo "Hello World From PHP!";
	    }
	?>
</body>
