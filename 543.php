<?php

$str = "";
for($i = 6;$i < 1000000; $i++){
    $str .= $i."\n";
}

file_put_contents("543.in4",$str);

?>
