public class Carro extends Veiculo {
    private int assentos;

    public Carro(String placa, String modelo, int assentos) {
        super(placa, modelo);
        this.assentos = assentos;
    }

    @Override
    public double calcularCusto(double distancia) {
        return 0.5 * distancia;
    }

    @Override
    public String getDetalhes() {
        return super.getDetalhes() + ", Assentos: " + assentos;
    }

    public int getAssentos() {
        return assentos;
    }

}
