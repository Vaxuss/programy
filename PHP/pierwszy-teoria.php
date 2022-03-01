<?php
    $db = mysqli_connect("localhost","root", "","nazwa bazy"); // łączenie z bazą danych (zapisujemy w zmiennej)
    //mysqli_connect("host","urzytkownik", "haslo","nazwa bazy")

    mysqli_close($db); // zamknięcie połączenia z bazą danych
    //mysqli_close(połączenie)

    $a = mysqli_query($db, "SQL") // zapytanie  zapisane w zmiennej Uwaga!: to sie wyona odrazu
    //mysqli_query(połączenie, "kod SQL")
    
    mysqli_fetch_row()
    //..._row tworzy tablice
    //..._assoc tworzy tablice asocjacyjną
    //..._array tworzy 2 tablice zwykłą i asocjacyjną

    print_r($row1); //wypisuje dane

    isset() // sprawdza czy zmienna istnieje (jest wypełniona)


?>