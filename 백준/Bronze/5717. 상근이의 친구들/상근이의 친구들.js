const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
input.forEach(tc => {
   const numbers = tc.split(" ");
   const [a, b] = numbers;
   if (a != 0 || b != 0)
       console.log(parseInt(a) + parseInt(b));
});