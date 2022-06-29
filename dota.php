<?php

if(isset($_GET["idvehicule"])) {
   $idvehicule = $_GET["idvehicule"];} 
if(isset($_GET["longtitude"])) {
   $longtitude = $_GET["longtitude"];
    
}
if(isset($_GET["lattitude"])) {
   $lattitude = $_GET["lattitude"];
   
}
if(isset($_GET["gps_date"])) {
   $gps_date = $_GET["gps_date"];
   
}
if(isset($_GET["gps_time"])) {
   $gps_time = $_GET["gps_time"];
   
}
/*if(isset($_GET["lattitude"])) {
   $longtitude = $_GET["lattitude"];}*/
   // REPLACE with Database user password
  $servername = "localhost";

// REPLACE with your Database name
$dbname = "gps_db";
// REPLACE with Database user
$username = "**********";
$password = '*************';


   // Create connection
   $conn = new mysqli($servername, $username, $password, $dbname);
   // Check connection
   if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
   }
   $sql1 = "SELECT * FROM gps where gps_time='$gps_time'";
$result = mysqli_query($conn, $sql1);

if (mysqli_num_rows($result) == 0) {
  // output data of each row
  $sql = "INSERT INTO gps (id_véhicule,lattitude,longtitude,gps_date,gps_time) VALUES ($idvehicule,$lattitude,$longtitude,'$gps_date','$gps_time')";

   if ($conn->query($sql) === TRUE) {
      echo "New record created successfully";
   } else {
      echo "Error: " . $sql . " => " . $conn->error;
   }

  }
  else {
   echo "location exist";
}
   $conn->close();
?>
