const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().split("\n");
const Klaudia = (((BigInt(input[0]) - BigInt(input[1])) / BigInt(2)) + BigInt(input[1])).toString();
const Natalia = ((BigInt(input[0]) - BigInt(input[1])) / BigInt(2)).toString();

console.log(Klaudia);
console.log(Natalia);