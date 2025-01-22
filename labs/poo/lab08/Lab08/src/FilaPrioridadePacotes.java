import java.util.PriorityQueue;

public class FilaPrioridadePacotes {
    private PriorityQueue<Pacote> filaPrioridade = new PriorityQueue<Pacote>();

    public void adicionarPacote(Pacote pacote) {
        filaPrioridade.add(pacote);
        System.out.println("Pacote adicionado com sucesso!");
    }

    public Pacote removerPacote() {
        return filaPrioridade.poll();
    }

    public void exibirFila() {
        for (Pacote pacote : filaPrioridade) {
            System.out.println(pacote);
        }
    }

    public boolean isEmpty() {
        return filaPrioridade.isEmpty();
    }
}