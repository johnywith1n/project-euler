<?php
	$a = "1";
	$b = "1";
	$sum = "0";
	$temp = "0";
	
	while(strlen($a) < 2) {
		while(strlen($b) < 2) {
			$temp = array_sum(str_split(bcpow($a, $b)));
			if(bccomp($temp,$sum) == 1) {
				$sum = $temp;	
			}
			$b = bcadd($b, "1");
		}
		
		$b = "1";
		$a = bcadd($a, "1");
	}
	
	echo $sum;
?>