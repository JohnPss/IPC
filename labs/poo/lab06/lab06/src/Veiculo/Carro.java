package Veiculo;

public class Carro extends Veiculo {
    private static final double CUSTO_POR_KM = 0.50;
    private int assentos;

    public Carro(String placa, String modelo, int capacidade, int assentos) {
        super(placa, modelo, capacidade);
        this.assentos = assentos;
    }

    public int getAssentos() {
        return assentos;
    }

    public void setAssentos(int assentos) {
        this.assentos = assentos;
    }

    @Override
    public double calcularCusto(double distancia) {
        return distancia * CUSTO_POR_KM;
    }

    @Override
    public String getDetalhes() {
        return "Tipo: Carro\n" +
                super.getDetalhes() +
                "\nNúmero de Assentos: " + assentos;
    }
}