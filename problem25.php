<?php
	$fib1 = "1";
	$fib2 = "1";
	$fibCurr = bcadd($fib1,$fib2);
	$index = 3;
		
	while(strlen($fibCurr) < 1000) {
		$fib1 = $fibCurr;
		$fibCurr = bcadd($fib1,$fib2);
		$fib2 = $fib1;
		$index++;
	}
	
	echo $index;
?>