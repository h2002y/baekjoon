const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().split("\n");
const [ax, ay, az] = input[0].split(" "), [cx, cy, cz] = input[1].split(" ");
const bx = cx - az, by = cy / ay, bz = cz - ax;
console.log(bx + " " + by + " " + bz);