<?php
    $db = mysqli_connect("localhost","root","","3b2");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php
    if(isset($_POST['login'])){
        $login = $_POST['login'];
        $password = sha1($_POST['password']);
        $q1 = "INSERT INTO `users`(`login`, `password`, `id_role`) 
            VALUES ('$login','$password','1')";
        if(mysqli_query($db,$q1))
            echo 'użytkownik dodany<br>
                <a href="login.php">logowanie</a>';
        else 
            echo 'nie dodano użytkownika';
    }
?>
    <form action="" method="post">
        <input type="text" name="login" id="">
        <input type="password" name="password" id="">
        <input type="submit" value="Zarejestruj">
    </form>
</body>
</html>
<?php
    mysqli_close($db);
?>