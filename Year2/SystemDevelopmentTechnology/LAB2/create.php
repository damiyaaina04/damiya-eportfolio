<html>

<head>
    <title>Student Registration Form</title>

    <style>
        h2 {
            background-color: rgb(66, 104, 124);
            color: white;
            font-size: 30px;
            font-family: 'Times New Roman', Times, serif;
            text-align: center;
        }

        body {
            background-color: rgb(179,216,184);
        }

        form {
            font-size: 25px;
        }
    </style>
</head>

<body>
    <h2>Student Registration Form</h2>
    <form action= "create.php" method="POST">

        <label> Student ID: </label>
        <input type="text" name="student_id" required><br>

        <label> Name: </label>
        <input type="text" name="name" required><br>

        <label> Email: </label>
        <input type="text" name="email" required><br>

        <label> Address: </label>
        <input type="text" name="address" required><br>

        <label> Program: </label>
        <input type="text" name="program" required><br>

        <label>Gender:</label><br>
        <input type="radio" id="male" name="gender" value="MALE">
        <label for="male">MALE</label><br>

        <input type="radio" id="female" name="gender" value="FEMALE">
        <label for="female">FEMALE</label><br>

        <input type="radio" id="other" name="gender" value="OTHER">
        <label for="other">OTHER</label><br><br>

        <button type="submit">Submit</button>
    </form>

    <a href="form.php">Back to Student registration list</a>
</body>

</html>

<?php //process utk msuk

include "db_conn.php"; //using database connection file here

if($_SERVER["REQUEST_METHOD"] == "POST"){

    $studentid = $_POST['student_id'];
    $name = $_POST['name'];
    $email = $_POST['email'];
    $address = $_POST['address'];
    $program = $_POST['program'];
    $gender = $_POST['gender'];

    $sql = "INSERT INTO studentregistration (student_id, name, email, address, program, gender) VALUES ('$studentid', '$name' , '$email','$address','$program','$gender')";

    if(mysqli_query($conn, $sql)){
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    }
}
?>