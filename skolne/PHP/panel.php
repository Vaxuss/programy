<?php
    $db = mysqli_connect("localhost","root","","3b2");
    session_start();

if(isset($_GET['zmien'])){
    $id_zmien = $_GET['zmien'];
}

    if(isset($_POST['login'])){
        $login = $_POST['login'];
        $password = sha1($_POST['password']);
        $q1 = "SELECT `id`,`id_role` FROM `users` WHERE 
            `login` LIKE '$login' AND `password` LIKE '$password'";
        $r1 = mysqli_query($db,$q1);
        if(mysqli_num_rows($r1)==1){
            $row1 = mysqli_fetch_row($r1);
            $_SESSION['id']=$row1[0];
            $_SESSION['role']=$row1[1];
        }
    }
    if(isset($_SESSION['id'])){
        $id = $_SESSION['id'];
//-------------------------------------------
        if(isset($_POST['login_change'])){
            if(isset($id_zmien)) $id = $id_zmien;
            $login = $_POST['login_change'];
            $q3 = "UPDATE `users` SET `login`='$login' WHERE `id`=$id";
            mysqli_query($db,$q3);
        }
        if(isset($_POST['old_pass'])){
            $old_pass = sha1($_POST['old_pass']);
            $q4 = "SELECT `id` FROM `users` WHERE `id` = $id AND `password` LIKE '$old_pass'";
            $r4 = mysqli_query($db,$q4);
            if((mysqli_num_rows($r4)==1) || (isset($id_zmien))){
                if($_POST['new_pass1']==$_POST['new_pass2']){
                    $new_pass = sha1($_POST['new_pass1']);
                    if(isset($id_zmien)) $id = $id_zmien;
                    $q5 = "UPDATE `users` SET `password`='$new_pass' WHERE `id`=$id";
                    if(mysqli_query($db,$q5)) echo 'haslo zostalo zmienione';
                    else echo 'blad zmiany hasla';
                }else echo 'hasla roznia sie od siebie';
            }else echo 'nieprawidlowe stare haslo';
        }
//------------------------------------------
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
    <form action="" method="post">
<?php
        if(isset($id_zmien)) $id = $id_zmien;
        $q2 = "SELECT `login` FROM `users` WHERE `id`=$id";
        $r2 = mysqli_query($db,$q2);
        $row2 = mysqli_fetch_row($r2);
        echo '<input type="text" name="login_change" id="" value="'.$row2[0].'">';
?>
        <input type="submit" value="zmien login">
    </form>
<?php
    if($_SESSION['role']>1){
?>
<hr>
<p>Zmiana hasla</p>
<form action="" method="post">
    <input type="password" name="old_pass" id=""><br>
    <input type="password" name="new_pass1" id="">
    <input type="password" name="new_pass2" id="">
    <input type="submit" value="Zmien haslo">
</form>
<hr>
<?php
    }
    if($_SESSION['role']>2){
        $q6 = "SELECT `users`.`id`, `users`.`login`, `role`.`nazwa`
        FROM `users` 
            LEFT JOIN `role` ON `users`.`id_role` = `role`.`id`
            WHERE `id_role` < 3";
        $r6 = mysqli_query($db,$q6);
        while($row6 = mysqli_fetch_row($r6))
            echo $row6[1].' '.$row6[2].' <a href="?zmien='.$row6[0].'">zmien</a><br>';
        echo '<a href = "panel.php">powrot</a><br>';
        echo '<a href="wyloguj.php">wyloguj</a>';
    }
?>

</body>
</html>
<?php
    }else
        echo 'nie zostales zalogowany<br>
            <a href="login.php">ZALOGUJ</a>';
    mysqli_close($db);
?>