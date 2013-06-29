<?php
	<?php
	$factorial = "1";
	$i = 1;
	
	while($i < 100) {
		$factorial = bcmul($factorial, "$i");
		$i++;
	}
	
	echo array_sum(str_split($factorial));
	
?>