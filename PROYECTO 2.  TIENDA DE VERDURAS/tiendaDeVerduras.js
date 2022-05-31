
/*

Sistema de inventario.

10 productos con nombre, precio, cantidad

Agregar, borrar, modificar.

Vender y comprar. (Solo se pueden comprar productos que existan, y no se puede vender, si no se tienen suficientes productos)
Se debe poder vender mas de un producto y al final dar el total de la venta o compra.

Menu con opciones

1.- Compra
2.- Venta
3.- Modificar productos
4.- Ver inventario
5.- Agregar productos

*/


// Variables
const inventario = [];
inventario.sort();


// Función para desplegar inventario.




// Función para agregar producto.

function agregar(){

    let $opciones = document.getElementById("productoEliminar");
    let $producto = document.getElementById("Producto").value;

    console.log(inventario.length);

    if (inventario.length === 10 ) {
         window.alert("No se pueden agregar más de 10 productos");
    }else{
        window.confirm(`Está seguro que quiere agregar el producto "${$producto}"?.`);
        window.alert(`El producto ${$producto} fue agregado correctamente`);
        inventario.push($producto);
        console.log(inventario);
        $opciones.innerHTML += `<option>${$producto}</option>`;
   
    }
}

// Función eliminar prodcuto.

function elminarProducto(){

    for (let index = 0; index < array.length; index++) {
        const element = array[index];
        let $productos2 /////////// continuación.
        if (opcion === element) {
            inventario.pop(element);
        }
        
    }
    console.log(inventario);

}


// Funciones para desplegar ventanas de trabajo  cerrar las ventanas.
function abrirInventario(){
    document.getElementById("ventanaInventario").style.display="block";
}
function abrirModificarProducto(){
    document.getElementById("ventanaModificarProducto").style.display="block";
}
function abrirAgregarProducto(){
    document.getElementById("ventanaAgregarProducto").style.display="block";
}
function abrirComprarProducto(){
    document.getElementById("ventanaComprarProducto").style.display="block";
}
function abrirVenderProducto(){
    document.getElementById("ventanaVenderProducto").style.display="block";
}

// Cerrar las ventanas de trabajo.
function cerrar0(){
    document.getElementById("ventanaInventario").style.display="none";
}
function cerrar1(){
    document.getElementById("ventanaModificarProducto").style.display="none";
}
function cerrar2(){
    document.getElementById("ventanaAgregarProducto").style.display="none";
}
function cerrar3(){
    document.getElementById("ventanaComprarProducto").style.display="none";
}
function cerrar4(){
    document.getElementById("ventanaVenderProducto").style.display="none";
}

//día.
date = new Date().toLocaleDateString();
document.write(date);

// Saludos para el ciego.

let texto = "Hola ciego, puedes probar mi aplicación para abarrotes, jaja saludos culebra.";

const hablar = (texto) => speechSynthesis.
speak(new SpeechSynthesisUtterance(texto));
hablar(texto);

