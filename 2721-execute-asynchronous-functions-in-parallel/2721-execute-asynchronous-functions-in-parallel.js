/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        let results = [];
        let count = 0;

        if (functions.length === 0) {
            resolve(results);
            return;
        }

        functions.forEach((fn, i) => {
            fn()
                .then(value => {
                    results[i] = value;
                    count++;

                    if (count === functions.length) {
                        resolve(results);
                    }
                })
                .catch(error => {
                    reject(error);
                });
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */