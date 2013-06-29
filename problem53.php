<?php
	$sum = 0;
	$n = 0;
	$r = 0;
	
	function combo($n, $k, $n_k) {
		$top = 1;
		$bottom = 1;
		
		if($n_k == 0) $n_k = 1;
		
		if($n_k > $k) {
			$big = $n_k;
			$small = $k;
		} else {
			$big = $k;
			$small = $n_k;
		}
		
		while($n > $big) {
			$top = bcmul($n,$top);
			$n--;		
		}
		
		while($small > 1) {
			$bottom = bcmul($bottom, $small);
			$small--;			
		}
		
		return bcdiv($top, $bottom);	
	}
	
	
	$myFile = "problem53.txt";
	$fh = fopen($myFile, 'w') or die("can't open file");
	
	
	while($n < 100) {
		$n++;
		while($r < $n) {
			$r++;
			$n_r = $n-$r;
			$temp = combo($n, $r, $n_r);			
			if(bccomp($temp, "1000000") == 1) $sum++;
		}
		$r = 0;		
	}
	
	fwrite($fh, $sum);

	fclose($fh);
?>