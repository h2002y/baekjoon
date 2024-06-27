const input = require('fs').readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().trim().split(" ");

const n = BigInt(input[0]), m = BigInt(input[1]);
const share = (n / m).toString();
const remainder = (n % m).toString();
console.log(share);
console.log(remainder);