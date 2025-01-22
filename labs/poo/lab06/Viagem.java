public class Viagem {
    private Motorista motorista;
    private Veiculo veiculo;
    private double distancia;

    public Viagem(Motorista motorista, Veiculo veiculo, double distancia) {
        this.motorista = motorista;
        this.veiculo = veiculo;
        this.distancia = distancia;
    }

    // public double calcularCusto() {
    // return veiculo.calcularCusto(distancia);
    // }

    public double calcularCustoTotal() {
        return 0.0;
    }

    public String getDetalhes() {
        return "Motorista: " + motorista.getNome() + ", " + veiculo.getDetalhes() + ", Distancia: " + distancia;
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

}
