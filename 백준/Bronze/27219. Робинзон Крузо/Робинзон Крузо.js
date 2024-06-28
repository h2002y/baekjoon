const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().trim();
const share = parseInt(input / 5), remainder = input % 5;
const five = "V", one = "I";
const answer = five.repeat(share) + one.repeat(remainder);
console.log(answer);