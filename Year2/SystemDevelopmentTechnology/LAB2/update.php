<html>
    <head>
        <title>Update Student Details</title>
    </head>

    <body>
        <h2>Update Student Details</h2>



        <?php 

        include "db_conn.php"; //using database connection filehere

        if(isset($_GET['student_id'])){    //check if id parameter is available
            $studentid = $_GET['student_id'];     // get the id parameter value
            $sql = "SELECT * FROM studentregistration WHERE student_id = $studentid"; //SQL query to select user data based on id
            $result = mysqli_query($conn, $sql); // execute the query
            $row = mysqli_fetch_assoc($result);   // fetch the result set into an associative array
        }

        ?>
        
        <form action= "update.php?student_id=<?php echo $row['student_id']; ?>" method="POST">

        <label> Student ID: </label>
        <input type="text" name="student_id" value="<?php echo $row['student_id']; ?>" required><br>

        <label> Name: </label>
        <input type="text" name="name" value="<?php echo $row['name']; ?>" required><br>

        <label> Email: </label>
        <input type="text" name="email"value="<?php echo $row['email']; ?>" required><br>

        <label> Address: </label>
        <input type="text" name="address" value="<?php echo $row['address']; ?>" required><br>

        <label> Program: </label>
        <input type="text" name="program"value="<?php echo $row['program']; ?>" required><br>

        <label>Gender:</label><br>
        <input type="radio" id="male" name="gender" value="<?php echo ($row['gender'] == 'MALE') ? 'checked' : ''; ?>" required>
        <label for="male">MALE</label><br>

        <input type="radio" id="female" name="gender" value="<?php echo ($row['gender'] == 'FEMALE') ? 'checked' : ''; ?>" required>
        <label for="female">FEMALE</label><br>

        <input type="radio" id="other" name="gender" value="<?php echo ($row['gender'] == 'OTHER') ? 'checked' : ''; ?>" required>
        <label for="other">OTHER</label><br>

        <button type="submit">UPDATE</button>
        
        </form>


        <?php

        if ($_SERVER["REQUEST_METHOD"] == "POST"){
            
            $studentid = $_POST['student_id'];
            $name = $_POST['name'];
            $email = $_POST['email'];
            $address = $_POST['address'];
            $program = $_POST['program'];
            $gender = $_POST['gender'];

            $sql = "UPDATE studentregistration SET student_id ='$studentid', name= '$name' , email='$email' , 
                    address='$address , program='$program, gender='$gender WHERE student_id=$studentid";

            if (mysqli_query($conn, $sql)){
                echo "Record updated successfully";
            } else{
                echo "Error: " . $sql . "<br>" . mysqli_error($conn);
            }
        }

        ?>
   
        <br>
        <a href="form.php">Back to student registration list</a>
    </body>

</html>