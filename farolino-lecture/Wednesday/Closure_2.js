var outerFunctionToMultiplyNumberBy10 = function(y) {
  
  var x = 10;

  var innerFunctionToMultiplyYBy10 = function() {
    return x*y;
  }

  return innerFunctionToMultiplyYBy10;
}

// Build my own function

var multiply5By10 = outerFunctionToMultiplyNumberBy10(5);

console.log( multiply5By10() );