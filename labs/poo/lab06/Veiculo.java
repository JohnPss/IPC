public class Veiculo {
    protected String placa;
    protected String modelo;

    public Veiculo(String placa, String modelo) {
        this.placa = placa;
        this.modelo = modelo;
    }

    public String getDetalhes() {
        return "Placa: " + placa + ", Modelo: " + modelo;
    }

    public double calcularCusto(double distancia) {
        return 0.0;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

}
