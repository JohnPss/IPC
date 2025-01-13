package Veiculo;

public abstract class Veiculo {
    private String placa;
    private String modelo;
    private int capacidade;

    public Veiculo(String placa, String modelo, int capacidade) {
        this.placa = placa;
        this.modelo = modelo;
        this.capacidade = capacidade;
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

    public int getCapacidade() {
        return capacidade;
    }

    public void setCapacidade(int capacidade) {
        this.capacidade = capacidade;
    }

    public abstract double calcularCusto(double distancia);

    public String getDetalhes() {
        return "Placa: " + placa +
                "\nModelo: " + modelo +
                "\nCapacidade: " + capacidade;
    }
}
