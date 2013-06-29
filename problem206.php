<?php
	$min = 101010103;
	$max = 138902663;

	$i = $min;
	
	function check ($num) {
		$square = bcmul($num, $num);
		
		if($square[0] == 1 && $square[2] == 2 && $square[4] == 3 && $square[6] == 4 && $square[8] == 5 &&
			$square[10] == 6 && $square [12] == 7 && $square[14] == 8 && $square[16] == 9) {
					return 1;
			} else {
				return 0;	
			}
	}
	
	while($i <= $max) {
		if(check($i)) break;
		if($i%10 == 3){
			$i = $i + 4;
		} else {
			$i = $i + 6;
		}
	}

	$i = bcmul("10", $i);
	
	$myFile = "problem206.txt";
	$fh = fopen($myFile, 'w') or die("can't open file");
	fwrite($fh, $i);
	fclose($fh);
?>