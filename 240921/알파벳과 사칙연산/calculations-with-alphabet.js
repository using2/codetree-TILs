const readline = require("readline");
let fomul;
let alphas = [];
let compare = [];
const arr = [1, 2, 3, 4];
let ans = 0;

function carculate() {
  const found = alphas.find(item => item.alpha === fomul[0]);
  let res = found.num;
  let oper;
  for(let i = 1; i < fomul.length; i++) {
    if(fomul[i] === "+" || fomul[i] === "-" || fomul[i] === "*"){
      oper = fomul[i];
      continue;
    } 

    const found = alphas.find(item => item.alpha === fomul[i]);
    const curNum = found.num;
    switch(oper) {
      case "+":
        res += curNum;
        break;
      case "-":
        res -= curNum;
        break;
      case "*":
        res *= curNum;
        break;
    }
  }

  return res;
}

function combine() {
  if(compare.length === alphas.length) {
    compare.forEach((a, i) => {
        alphas[i].num = a;
    })

    let curAns = carculate();
    if(ans < curAns) ans = curAns;
    return;
  }

  for(let i = 1; i <= 4; i++) {
    compare.push(i);
    combine();
    compare.pop(i);
  }
}

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", (line) => { 
    const alpha = "abcdefghijklmnopqrstuvwxyz";
    fomul = line;

    alpha.split("").forEach(a => {
      if(fomul.indexOf(a) !== -1) {
        alphas.push({alpha: a, num: 0}); 
      }
    });

    combine();
    console.log(ans);

    rl.close(); 
});
 
rl.on('close', () => { })