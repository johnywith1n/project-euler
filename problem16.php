<?php
	$pow = bcpow("2", "1000");
	
	$count = 0;
	$sum = 0;
	$len = strlen($pow);

	while($count < $len) {
		$sum = $sum + $pow[$count];
		$count++;
	}

	echo $sum;
?>