<?php
	$i = 1;
	$sum = "0";
	
	while($i < 1000) {
		$sum = bcadd($sum, bcpow("$i", "$i"));
		$i++;
	}
	
	echo bcmod($sum, bcpow("10","10"));
?>