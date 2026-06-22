<?php 

include "db_conn.php"; //using database connection filw here

if(isset($_GET['student_id'])){   //check if id parameter is available

    $studentid = $_GET['student_id'];     // get the id parameter value

    $sql = "DELETE FROM studentregistration WHERE student_id=$id"; //SQL query to select user data based on id
    $result = mysqli_query($conn, $sql); // execute the query

    if ($result){
        echo "<script>alert('User Deleted Successfully'); window.location='form.php'</script>";
    } else {
        echo "<script>alert('User Not Deleted'); window.location='form.php'</script>";
    }
    }
    ?>
