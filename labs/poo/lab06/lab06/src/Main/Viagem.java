package Main;

import Veiculo.Veiculo;
import Motorista.Motorista;

public class Viagem {
    private Motorista motorista;
    private Veiculo veiculo;
    private double distancia;

    public Viagem(Motorista motorista, Veiculo veiculo, double distancia) {
        this.motorista = motorista;
        this.veiculo = veiculo;
        this.distancia = distancia;
    }

    public Motorista getMotorista() {
        return motorista;
    }

    public void setMotorista(Motorista motorista) {
        this.motorista = motorista;
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public void setVeiculo(Veiculo veiculo) {
        this.veiculo = veiculo;
    }

    public double getDistancia() {
        return distancia;
    }

    public void setDistancia(double distancia) {
        this.distancia = distancia;
    }

    public double calcularCustoTotal() {
        return veiculo.calcularCusto(distancia);
    }

    public String getDetalhes() {
        return "Detalhes da Viagem:\n" +
                "=================\n" +
                "Motorista:\n" + motorista.getDetalhes() + "\n\n" +
                "Veículo:\n" + veiculo.getDetalhes() + "\n\n" +
                "Distância: " + distancia + " km\n" +
                "Custo Total: R$ " + String.format("%.2f", calcularCustoTotal());
    }
}
