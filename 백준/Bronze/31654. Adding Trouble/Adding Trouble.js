const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().trim().split(" ").map(BigInt);
const [A, B, C] = input;
if (A + B === C) console.log("correct!");
else console.log("wrong!");