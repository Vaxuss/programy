<?php
    session_start();
    $db = mysqli_connect("localhost","root","","3b1");

    if(isset($_POST['login'])){
        $login = $_POST['login'];
        $password = sha1($_POST['password']);
        $q1 = "SELECT `id`, `id_role` FROM `users`
            WHERE `login` LIKE '$login' AND `password` LIKE '$password' ";
        $r1 = mysqli_query($db,$q1);
        $m1 = mysqli_num_rows($r1);
        if($m1 == 1){
            $row1 = mysqli_fetch_row($r1);
            $_SESSION['id'] = $row1[0];
            $_SESSION['role'] = $row1[1];
            print_r($_SESSION);
        }

        // $session_start();
        //     $_SESSION['nazwa'] = 5;
        //     unset($zmienna)
        // $session_destroy();
        // $_SESSION = array();
    }
    if(isset($_SESSION['id'])){

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
        Witaj w panelu;
</body>
</html>

<?php
    }else{
        echo 'error. log again: <a href = "login.php">link</a>';
    }
    mysqli_close($db);
?>