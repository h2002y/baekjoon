const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().split(" ").map(Number);
const [A, B] = input;
console.log(B - A+ " " + B);