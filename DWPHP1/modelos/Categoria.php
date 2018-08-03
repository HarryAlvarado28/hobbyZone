<?php
/**
 * Created by PhpStorm.
 * User: harry
 * Date: 08/02/18
 * Time: 10:21 PM
 */

require '../config/Conexion.php';

class Categoria{
    public function _construct(){

    }

    public function insertar($nombre, $description){
        $sql = "INSERT INTO categoria (nombre, descripcion, condicion) VALUES ('$nombre','$description','1')";
        return ejecutarConsulta($sql);
    }

    public function editar($idcategoria,$nombre,$descripcion){
        $sql = "UPDATE categoria SET nombre='$nombre',descripcion='$descripcion' where idcategoria='$idcategoria'";
        return ejecutarConsulta($sql);
    }

    public function desactivar ($idcategoria){
        $sql = "UPDATE categoria SET condicion='0' WHERE idcategoria='$idcategoria'";
        return ejecutarConsulta($sql);
    }

    public function activar ($idcategoria){
        $sql = "UPDATE categoria SET condicion='1' WHERE idcategoria='$idcategoria'";
        return ejecutarConsulta($sql);
    }

    public function mostrar($idcategoria){
        $sql = "SELECT * FROM categoria WHERE idcategoria='$idcategoria'";
        return ejecutarConsultaSimpleFila($sql);
    }

    public function listar(){
        $sql = "SELECT * FROM categoria";
        return ejecutarConsulta($sql);
    }

    public function select(){
        $sql = "SELECT * FROM categoria where  condicion = 1";
        return ejecutarConsulta($sql);
    }
}
