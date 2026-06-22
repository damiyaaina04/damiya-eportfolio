<html>
    <head>
        <title>Registration Form</title>

        <style>
            h2{
                background-color: rgb(167,193,225);
                font-size: 45px;
                text-align: center;
            }

            body{
                background-color: rgb(96,123,155);
            }

            table {
                border-collapse: collapse;
                width: 98%;
            }

            .sec-row{
                background-color: rgb(221,167,105);
            }
        </style>
    </head>

    <body>
    <h2>Student Registration List</h2>
    <table border="1">
        <tr style="background-color: rgb(198,113,12);">
            <td> Student ID </td>
            <td> Name </td>
            <td> Email </td>
            <td> Address </td>
            <td> Program </td>
            <td> Gender </td>
            <td> Edit </td>
            <td> Delete </td>
        </tr>

        <?php

        include "db_conn.php";

        $sql = "SELECT * FROM studentregistration";
        $result = mysqli_query($conn, $sql);

        if(mysqli_num_rows($result) > 0){
            while ($row = mysqli_fetch_assoc($result)){
                echo "<tr class='sec-row'>";
                echo "<td>" . $row['student_id'] . "</td>";
                echo "<td>" . $row['name'] . "</td>";
                echo "<td>" . $row['email'] . "</td>";
                echo "<td>" . $row['address'] . "</td>";
                echo "<td>" . $row['program'] . "</td>";
                echo "<td>" . $row['gender'] . "</td>";
                echo "<td>" . "<a href='update.php?id=" . $row['student_id'] . "'>Edit</a></td>";
                echo "<td>" . "<a href='delete.php?id=" . $row['student_id'] . "'>Delete</a></td>";
                echo "</tr>";
            } 
        }else {
            echo "<tr><td colspan='8'>No Data Found</td></tr>";
        }

        ?>

    </table>

    <a href="create.php">New Student Registration</a>

</body>
</html>

</html>