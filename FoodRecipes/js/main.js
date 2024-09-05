// V A R I A B L E S
let api = new XMLHttpRequest;
let container = document.querySelector(".container .row")
let searchData = document.querySelector("#search");
let newArr = [];
let key = document.querySelector("select")

getData('pizza')

// E V E N T  L I S T E N E R S
key.addEventListener("change",function () {
    getData(this.value)
})

document.addEventListener("click", function (event) {
    if (event.target != searchData) {
        let searched = []
        let allData = JSON.parse(api.response);
        let data = searchData.value.toLowerCase();

        for (let i = 0; i < allData.recipes.length; i++) {
            if (allData.recipes[i].title.toLowerCase().includes(data)) {
                searched.push(allData.recipes[i])
            }
        }

        showData(searched)
    }
})

document.addEventListener("keyup", function (event) {
    if (event.key == "Enter") {
        let searched = []
        let allData = JSON.parse(api.response);
        let data = searchData.value.toLowerCase();

        for (let i = 0; i < allData.recipes.length; i++) {
            if (allData.recipes[i].title.toLowerCase().includes(data)) {
                searched.push(allData.recipes[i])
            }
        }

        showData(searched)
    }
})

// F U N C T I O N S
function getData(data) {
api.open("GET", `https://forkify-api.herokuapp.com/api/search?q=${data}`);

api.send();

api.addEventListener("readystatechange", function () {
    if (this.readyState == 4) {
        let allData = JSON.parse(api.response);

        showData(allData.recipes)
    }
})    
}

function showData(array) {
    let cartona = ``;

    for (let i = 0; i < array.length; i++) {

        cartona += `<div class="recipe p-2 d-flex align-items-center justify-content-center flex-column col-sm-12 my-3">

                    <div class="image overflow-hidden"><img src="${array[i].image_url}"alt="Pizza-img"></div>
                    
                    <div class="description pt-4">
                        <p><span>Title : </span>${array[i].title}</p>
                        <p><span>Recipe id : </span> ${i + 1}</p>
                        <p><span>Social rank : </span>${array[i].social_rank}</p>
                        <p><span>publisher : </span>${array[i].publisher}</p>
                     </div>
                     
                     </div>`
    }
    container.innerHTML = cartona;
}