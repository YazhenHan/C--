Function.prototype.bind = function (obj, ...args1) {
    const fn = this;
    return (...args2) => {
        return fn.apply(obj, [...args1, ...args2]);
    };
}

function introduce() {
  console.log(`我是 ${this.name}`);
}

const tom = {
  name: "Tom"
};

const jerry = {
  name: "Jerry"
};

const tomIntroduce = introduce.bind(tom);
const jerryIntroduce = introduce.bind(jerry);

tomIntroduce();
// 我是 Tom

jerryIntroduce();
// 我是 Jerry