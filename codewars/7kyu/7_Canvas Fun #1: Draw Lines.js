function drawLines(a) {
    var canvas = new Canvas(100,100)  //Create a 100 x 100 canvas
    var ctx = canvas.getContext('2d');
    ctx.fillStyle="#ffffff"
    ctx.fillRect(0,0,100,100)  //Draw background
    ctx.strokeStyle="#ff0000"  //Set pen's color
    ctx.beginPath()
    //Don't delete or modify the code above
    //Your code starts here:

    //This is an example, it will draw a line from point(0,0) to point(99,99)
    ctx.moveTo(...a[0])
    for(let i=1;i<a.length;i++)
        ctx.lineTo(...a[i])

    //Don't delete or modify the following code
    ctx.stroke()              //Draw the path you made above
    return canvas.toDataURL() //Returns the image data
}