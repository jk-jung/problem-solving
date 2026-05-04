function removeNoise(str){
	return str.split('').filter(x => !`%$&/#·@|º\\ª`.includes(x)).join('')
}