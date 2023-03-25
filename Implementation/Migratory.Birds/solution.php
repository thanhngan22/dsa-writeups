<?php

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

function migratoryBirds($arr) {
    // Write your code here
    $count_arr = array_count_values($arr);
    $maxCount = 0;
    $Value = 0;
    foreach ($count_arr as $key => $value) {
        if ($value > $maxCount) {
            $maxCount = $value;
            $Value = $key;
        }
        else if ($value == $maxCount ) {
            if ($Value > $key) {
                $Value = $key;
            }
        }
    }
    return $Value;

}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$arr_count = intval(trim(fgets(STDIN)));

$arr_temp = rtrim(fgets(STDIN));

$arr = array_map('intval', preg_split('/ /', $arr_temp, -1, PREG_SPLIT_NO_EMPTY));

$result = migratoryBirds($arr);

fwrite($fptr, $result . "\n");

fclose($fptr);
