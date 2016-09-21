function outerFunction() {
  console.log("outerFunction has been entered");

  var innerFunction = function() {
    console.log("innerFunction has been entered");
  }

  return innerFunction;
}

var variableToCaptureInnerFunction = outerFunction();

//variableToCaptureInnerFunction();

//SlideVisOfClosure